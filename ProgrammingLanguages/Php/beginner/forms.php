<?php
    /** Post request */
    $name = $_POST["name"];
    // $name = $_GET["name"];
    switch ($name) {
        case 'q':
            echo "Welcome admin <br />";
            break;
        
        default:
            echo "Hello guest <br />";
            break;
    }
?>

<h2>Get form</h2>
<form method="GET" action="forms.php">
    <input type="text" name="name" placeholder="Type your username">
    <button type="submit">Submit</button>
</form>

<h2>Post form</h2>
<form method="POST" action="forms.php">
    <input type="text" name="name" placeholder="Your username">
    <button type="submit">Sumit</button>
</form>
