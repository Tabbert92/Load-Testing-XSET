Action()
{
	lr_start_transaction("UC_01_LoginLogout");
	
		lr_start_transaction("openHomePage");

		loadStartingPage();
		
		lr_end_transaction("openHomePage", LR_AUTO);
		
		lr_think_time(5);
		
		lr_start_transaction("login");
		
			login();
	
		lr_end_transaction("login",LR_AUTO);
	
		lr_think_time(5);
		
		lr_start_transaction("browsingItenerary");
		
			web_reg_find("Fail=NotFound",
					"Text=Itinerary",
					LAST);
		
			web_url("Itinerary Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t8.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("browsingItenerary",LR_AUTO);
		
		lr_think_time(5);
	
		lr_start_transaction("logout");
		
			logout();
	
		lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("UC_01_LoginLogout", LR_AUTO);

	return 0;
}