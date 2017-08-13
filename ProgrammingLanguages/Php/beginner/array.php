<?php 
    /** Simple array and dict */
    $cities = array("Ho Chinh City", "New York", "Tokyo");
    $employes = array("Join" => "500$", "Mark" => "600$", "Bill" => "600$");

    $cities[4] = "London";
    echo $cities[4] . "<br />";
    echo $employes["Join"] . "<br />";

    /** Multidimension array */
    $students = array (
        array("Mark", 15, 46),
        array("Join", 13, 65),
        array("Tom", 14, 56)
    );
    echo "Name of first item " . $students[0][0];
?>