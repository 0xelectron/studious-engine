<?php

    require("../includes/config.php");
    
    $histories = query("SELECT * FROM history WHERE id = ? ", $_SESSION["id"]);
    
 
    render("history_display.php",["histories" => $histories,"title"=> "history"]);

?>
