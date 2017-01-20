<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        if(empty($_POST["username"]) )
        {
            apologize("please provide a username");
        }
        if( empty($_POST["password"] ))
        {
            apologize("please provide a password");
        }
        if (empty($_POST["confirmation"]))
        {
            apologize("Please provide a confirmation");
        }
        if ( $_POST["password"] != $_POST["confirmation"])
        {
            apologize("password dosen't match");
        }
        
        $results=query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));
        
        if ($results === false)
        {
            apologize("username already exists");
        }    
        
        
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
    
        // remember that user's now logged in by storing user's ID in session
        $_SESSION["id"] = $id;

        // redirect to portfolio
        redirect("/");
    
    }
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>

