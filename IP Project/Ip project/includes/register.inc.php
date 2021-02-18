<?php

session_start();
include_once 'connect.local.php';

if (isset($_POST['submit'])) {

    #Treat user input as text and not as code
    $firstname = mysqli_real_escape_string($conn, $_POST['firstname']);
    $lastname = mysqli_real_escape_string($conn, $_POST['lastname']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $contact = mysqli_real_escape_string($conn, $_POST['contact']);
    $pass = mysqli_real_escape_string($conn, $_POST['pass']);
    $repass = mysqli_real_escape_string($conn, $_POST['repass']);
    

    // Set up session variables so if error occurs user doesn't have to fill entire form
    $_SESSION['formFilled'] = true;
    $_SESSION['firstname'] = $firstname;
    $_SESSION['lastname'] = $lastname;
    $_SESSION['email'] = $email;
    $_SESSION['contact'] = $contact;
    $_SESSION['pass'] = $pass;


    // Form Validation / Error Handlers
    // Check for empty fields
    if(empty($firstname) || empty($lastname) || empty($email) || empty($pass) || 
        empty($repass)) {
        header("Location: ../register.php?signup=empty");
        exit();
    } else if(!preg_match("/^[a-zA-Z]*$/", $firstname) || !preg_match("/^[a-zA-Z]*$/", $lastname)
              ){
        // Check if input characters are Valid i.e if they only contain a-z and A-Z
        header("Location: ../register.php?signup=invalid");
        exit();
    } else if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        // Check if email is Valid
        header("Location: ../register.php?signup=email");
        exit();
    } else if(strlen($pass) < 8){
        //Check if password is valid
        header("Location: ../register.php?signup=len");
        exit();
    } else if($contact <=10000000 || $contact >= 99999999999) {
        //Check if phone is valid
        header("Location: ../register.php?signup=contact");
        exit();
    } else {

        // Check if user doesn't already exist i.e. email is not in db
        $sql = "SELECT * FROM users WHERE email='$email';";
        $result = mysqli_query($conn, $sql);
        $resultCheck = mysqli_num_rows($result);
        if($resultCheck > 0) {
            header("Location: ../register.php?signup=taken");
            exit();
        } else if(strcmp($pass,$repass) !== 0) {
            //Check if both passwords match
            header("Location: ../register.php?signup=pass");
            exit();
        } else {
            // Hashing the password
            $hashedPass = password_hash($pass, PASSWORD_DEFAULT);
            // Insert the user in the db
            // if (move_uploaded_file($_FILES['signature']['tmp_name'], $signtarget) && move_uploaded_file($_FILES['profilepic']['tmp_name'], $profiletarget)){
                $sql = "INSERT INTO users (firstname, lastname, email, pass, contact) 
                        VALUES ('$firstname', '$lastname','$email', '$hashedPass', '$contact');";
                mysqli_query($conn, $sql) or die(mysqli_error($conn));
                // Now redirect the user
                header("Location: ../register.php?signup=success");
                exit();
            // }else{
            //     header("Location: ../add_event.php?signup=signupload");
            //     exit();
            // }
        }
    }
} else {
  // If someone just loads the url without submitting data
  header("Location: ../register.php");
  exit();
}