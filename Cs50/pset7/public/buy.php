<?php
    
     // configuration
    require("../includes/config.php");
    
     
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        if(preg_match("/^\d+$/", $_POST["shares"]) == false)
        {
            apologize("Invalid number of Shares");
        }
        
        
        $cash = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
        
        
        $stock = lookup($_POST["symbol"]);
        
        if($stock == false)
        {
            apologize ("No such stock symbol");
        }
        
        $stock_price = $_POST["shares"] * $stock["price"];
        
        
        if( $stock_price > $cash[0]["cash"])
        {
            apologize("You can't afford that no. of cash ");
        }
        
         $update = query("UPDATE users SET cash = cash - ? WHERE id = ? ", $stock_price ,$_SESSION["id"]);  
        
        if($update === false)
        {
        	apologize("not able to update your shares!");
        }
        
        
        $stock_add = query("INSERT INTO stock_manager (id,symbol,shares) VALUES (?,?,?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"] , strtoupper($_POST["symbol"]),$_POST["shares"]);
        
        if($stock_add === false)
        {
            apologize("No stock of such symbol in your portfolio");
        }
        

        $history=query("INSERT INTO history (id,transaction,dt,symbol,shares,price) VALUES (?,'BUY',CURRENT_TIMESTAMP,?,?,?) ", $_SESSION["id"] ,strtoupper($_POST["symbol"]),$_POST["shares"],$stock["price"]);
        
        
        if($history === false)
        {
        	apologize("could not add to your portfolio histroy");
        }
        
        
        redirect("/");
    }
    
   
    
    else
    {
        // else render form
        render("buy_form.php", ["title" => "Buy" ]);
    }
    
?>
