<?php 
    /** While loop */
    $counter = 1;
    while ($counter < 10) {
        echo "Hello While ". $counter . "<br />";
        $counter ++;
    }

    /** Do while loop */
    do {
        echo "Do while ". $counter . "<br />";
        $counter ++;
    } while ($counter < 20);

    /** For loop */
    for ($i = 0; $i < 10; ++$i) {
        echo "Hello from for loop " . $i . "<br />";
    }

    /** For each loop */
    $employes = array("Join" => "500$", "Mark" => "600$", "Bill" => "600$");
    /** Loop through key - value pairs */
    foreach ($employes as $key => $value) {
        echo "Name ". $key . " Sallary " . $value . "<br />";
    }

    foreach ($employes as $value) {
        echo "Weight ". $value . "<br />";
    }

    /** Switch case */
    $number = 10;
    switch ($number) {
        case '10':
            echo "Hello Q <br />";
            break;
        
        default:
            echo "Nothing <br />";
            break;
    }
?>