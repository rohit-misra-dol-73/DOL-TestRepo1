<?php
//Now this page can have sessions
session_start();
include_once 'connect.local.php';

if(isset($_POST['submit'])) {
  $email = mysqli_real_escape_string($conn, $_POST['email']);
  $pass = mysqli_real_escape_string($conn, $_POST['pass']);
  //Error Handlers
  // Check if inputs are empty
  if(empty($email) || empty($pass)) {
    header("Location: ../login.php?login=empty");
    exit();
  } else {
    $sql = "SELECT * FROM users where   email='$email';";
    $result = mysqli_query($conn, $sql);
    $resultCheck = mysqli_num_rows($result);
    if($resultCheck < 1) {
      header("Location: ../login.php?login=error");
      exit();
    } else {
      if($row = mysqli_fetch_assoc($result)) {
        // Dehashing the password
        $hashedPassCheck = password_verify($pass, $row['pass']);
        if($hashedPassCheck == false) {
          header("Location: ../login.php?login=error");
          exit();
        } elseif($hashedPassCheck == true) {
          // Login the user here use a common variable called $_SESSION
          $_SESSION['u_id'] = $row['  id'];
          $_SESSION['u_first'] = $row['  firstname'];
          $_SESSION['u_last'] = $row['  lastname'];
          $_SESSION['u_email'] = $row['  email'];
          $_SESSION['u_contact'] = $row['  contact'];
          
          if(strcmp($email, "admin@ieee.com") == 0) {
            $_SESSION['privilege'] = "admin";
          } else {
            $_SESSION['privilege'] = "member";
          }
          header("Location: ../shoes.php");
          exit();
        }
      }
    }
  }
} else {
  header("Location: ../login.php");
  exit();
}