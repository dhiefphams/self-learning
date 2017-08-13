<?php
    $host = "localhost:3306";
    $db_user = "root";
    $db_pass = "root";
    $db_name = "test_db";

    $connection = mysqli_connect($host, $db_user, $db_pass, $db_name);
    if (empty($connection)) {
        die("Cannot connect to db");
        return;
    }

    echo "Done";
?>