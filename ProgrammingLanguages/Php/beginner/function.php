<?php
    /** Variable scrope */
    $name = 'Q';
    function hello() {
        global $name;
        echo "Hello ". $name;
    }

    function max(a, b) {
        return a > b ? a : b;
    }
    hello();
?>