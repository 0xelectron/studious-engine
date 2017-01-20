<?php

    // configuration
    require("../includes/config.php"); 

    $positions = [];

    $rows = query("SELECT * FROM stock_manager WHERE id = ?",$_SESSION["id"]);    
    $cash = query("SELECT * FROM users WHERE id = ?",$_SESSION["id"]);
    
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }
    
    // render portfolio
    render("portfolio.php",["positions" => $positions,"cash"=> $cash,"title" => "Portfolio"]);

?>
