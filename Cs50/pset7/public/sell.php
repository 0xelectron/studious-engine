<?php
    
     // configuration
    require("../includes/config.php");
    
     $stocks = query("SELECT * FROM stock_manager WHERE id = ? ", $_SESSION["id"]);
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $shares = query("SELECT shares FROM stock_manager WHERE symbol = ? and id = ?", strtoupper($_POST["symbol"]),$_SESSION["id"]);
       
        $stock = lookup($_POST["symbol"]);
        
        $stock_price = $shares[0]["shares"] * $stock["price"];
        
        $update = query("UPDATE users SET cash = cash + ? WHERE id = ? ", $stock_price ,$_SESSION["id"]); 
        
        if($update === false)
        {
        	apologize("not able to update your cash");
        }
        
        $history=query("INSERT INTO history (id,transaction,dt,symbol,shares,price) VALUES (?,'SELL',CURRENT_TIMESTAMP,?,?,?) ", $_SESSION["id"] ,strtoupper($_POST["symbol"]) ,$shares[0]["shares"],$stock["price"]);
        
        if($history === false)
        {
        	apologize("could not add to your portfolio histroy");
        }
         
       
       
        $stock_delete = query("DELETE FROM stock_manager WHERE id = ? AND symbol = ?", $_SESSION["id"] ,strtoupper($_POST["symbol"]));
        
        if($stock_delete === false)
        {
            apologize("No stock of such symbol in your portfolio");
        }
        
       
        redirect("/");
    }
    
   
    
    else
    {
        // else render form
        render("sell_form.php", [ "stocks" => $stocks , "title" => "Sell" ]);
    }
    
?>
