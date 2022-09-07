Action()
{
	lr_start_transaction("UC_06_RegistraitionRandomUser");
	
		lr_start_transaction("openHomePage");

		loadStartingPage();
		
		lr_end_transaction("openHomePage", LR_AUTO);
		
		lr_think_time(5);
	
		lr_start_transaction("signUpNowButtonClick");
	
			web_link("sign up now", 
				"Text=sign up now", 
				"Snapshot=t2.inf", 
				LAST);
		lr_end_transaction("signUpNowButtonClick",LR_AUTO);
	
		lr_think_time(5);
	
		lr_start_transaction("newUserRegistration");
	
			generateRandomWord(5);
			lr_save_string(lr_eval_string("{randomWord}"), "userName");
			
			generateRandomWord(4);
			lr_save_string(lr_eval_string("{randomWord}"), "password");
			
			generateRandomWord(5);
			lr_save_string(lr_eval_string("{randomWord}"), "firstName");
			
			generateRandomWord(5);
			lr_save_string(lr_eval_string("{randomWord}"), "lastName");
			
			generateRandomWord(6);
			lr_save_string(lr_eval_string("{randomWord}"), "address1");
			
			generateRandomWord(6);
			lr_save_string(lr_eval_string("{randomWord}"), "address2");
		
			web_reg_find("Fail=NotFound",
					"Text=Thank you, <b>{userName}</b>, for registering",
					LAST);
	
			web_submit_form("login.pl", 
				"Snapshot=t3.inf", 
				ITEMDATA, 
				"Name=username", "Value={userName}", ENDITEM, 
				"Name=password", "Value={password}", ENDITEM, 
				"Name=passwordConfirm", "Value={password}", ENDITEM, 
				"Name=firstName", "Value={firstName}", ENDITEM, 
				"Name=lastName", "Value={lastName}", ENDITEM, 
				"Name=address1", "Value={address1}", ENDITEM, 
				"Name=address2", "Value={address2}", ENDITEM, 
				"Name=register.x", "Value=37", ENDITEM, 
				"Name=register.y", "Value=8", ENDITEM, 
				LAST);

		lr_end_transaction("newUserRegistration",LR_AUTO);
	
		lr_think_time(5);
	
		lr_start_transaction("continueButtonClick");
	
			web_reg_find("Fail=NotFound",
			"Text=Welcome, <b>{userName}</b>, to the Web Tours reservation pages",
			LAST);
	
			web_image("button_next.gif", 
				"Src=/WebTours/images/button_next.gif", 
				"Snapshot=t4.inf", 
				LAST);
	
		lr_end_transaction("continueButtonClick",LR_AUTO);
	
		lr_think_time(5);
	
		/*lr_start_transaction("logout");
	
			logout();

		lr_end_transaction("logout",LR_AUTO);*/
	
	lr_end_transaction("UC_06_RegistraitionRandomUser", LR_AUTO);

	return 0;
}

void generateRandomWord(int numberOfLetters)
{
	int i;
	
	lr_param_sprintf("randomWord", "%s", lr_eval_string("{alphabet}"));
 	
 	for (i = 0; i < numberOfLetters; i++)
 		lr_param_sprintf("randomWord", "%s%s", lr_eval_string("{randomWord}"), lr_eval_string("{alphabet}"));
}