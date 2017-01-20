<?php
    
     // configuration
    require("../includes/config.php");
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        $stock = lookup($_POST["symbol"]);
        
        if($stock == false)
        {
            apologize("No stock for such symbol");
        }
        
        
        render("quote_display.php",$stock);
    }
    
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    
     


?>
