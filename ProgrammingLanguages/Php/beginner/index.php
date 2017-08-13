<?php
    /**
     * The require() function is identical to include(), except that it 
     * handles errors differently. If an error occurs, the include() 
     * function generates a warning, but the script will continue 
     * execution. The require() generates a fatal error, and the script 
     * will stop.
     */
    include 'header.php';
    /**
     * The require_once() statement is identical to require() except PH 
     * will check if the file has already been included, and if so, not 
     * include (require) it again.
    */
   
    include_once 'header.php';
    /** Start a session that already set in session.php */
    session_start();
?>

<h1>Hello world</h1>

<?php
    /** Destroy all session vairable */
    // session_destroy();
    echo "Session variable " . $_SESSION["hello"] . "<br />";
?>

