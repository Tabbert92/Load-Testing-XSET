Action()
{

	lr_start_transaction("AUX_AddingUsersToWebTours");
	
	web_reg_find("Fail=NotFound",
			"Text/IC=A Session ID has been created and loaded into a cookie",
			LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	web_set_sockets_option("SSL_VERSION", "AUTO");


	lr_start_transaction("NewUserRegistration");
	
		web_link("sign up now", 
			"Text=sign up now", 
			"Snapshot=t2.inf", 
			LAST);
	
		web_reg_find("Fail=NotFound",
				"Text=We hope we can meet all your current and future travel needs",
				LAST);
	
		web_submit_form("login.pl", 
			"Snapshot=t3.inf", 
			ITEMDATA, 
			"Name=username", "Value={userName}", ENDITEM, 
			"Name=password", "Value={password}", ENDITEM, 
			"Name=passwordConfirm", "Value={password}", ENDITEM, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={lastName}", ENDITEM, 
			"Name=address1", "Value={adress1}", ENDITEM, 
			"Name=address2", "Value={adress2}", ENDITEM, 
			"Name=register.x", "Value=37", ENDITEM, 
			"Name=register.y", "Value=8", ENDITEM, 
			LAST);

	lr_end_transaction("NewUserRegistration",LR_AUTO);
	

	lr_start_transaction("ContinueAfterRegistration");
	
		web_reg_find("Fail=NotFound",
		"Text=User has returned to the home page",
		LAST);

		web_image("button_next.gif", 
			"Src=/WebTours/images/button_next.gif", 
			"Snapshot=t4.inf", 
			LAST);
	
	lr_end_transaction("ContinueAfterRegistration",LR_AUTO);
	

	lr_start_transaction("logout");
	
		web_reg_find("Fail=NotFound",
				"Text/IC=A Session ID has been created and loaded into a cookie",
				LAST);

		web_image("SignOff Button", 
			"Alt=SignOff Button", 
			"Snapshot=t5.inf", 
			LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("AUX_AddingUsersToWebTours", LR_AUTO);

	return 0;
}