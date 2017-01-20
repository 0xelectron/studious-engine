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
        
        $password_update = query("UPDATE users SET hash = ? WHERE username = ? ", crypt($_POST["password"]) , $_POST["username"]);
        
        if($password_update === false)
        {
            apologize("Can't reset password at the mommnet!! please try again later!!!!");
        }

        redirect("/");
            
    }

    else
    {
        // else render form
        render("password_reset_form.php", ["title" => "Password Reset"]);
    }

?>
