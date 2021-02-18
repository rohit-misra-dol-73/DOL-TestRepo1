<?php
$dbServername= "localhost";
$dbUsername= "phpmyadmin";
$dbPassword= "methipak";
$dbName= "footstepsDb";
$conn = mysqli_connect($dbServername, $dbUsername, $dbPassword, $dbName) or die("Connection failed");
