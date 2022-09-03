Action()
{
	int flightIdLegth;
	int randomNumber;
	
	lr_start_transaction("UC_04_ItineraryListBrowsing");
	
		web_reg_save_param("userSession",
			"LB=name=\"userSession\" value=\"",
			"RB=\"",
			LAST);

		web_url("WebTours", 
			"URL=http://localhost:1080/WebTours/", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);
		
		web_set_sockets_option("SSL_VERSION", "AUTO");
	
		lr_think_time(5);
	
		lr_start_transaction("login");
		
				web_reg_find("Fail=NotFound",
					"Search=Body",
					"Text=Welcome, <b>{userName}</b>",
					LAST);
	
				web_submit_data("login.pl", 
					"Action=http://localhost:1080/cgi-bin/login.pl", 
					"Method=POST", 
					"TargetFrame=body", 
					"RecContentType=text/html", 
					"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
					"Snapshot=t2.inf", 
					"Mode=HTML", 
					ITEMDATA, 
					"Name=userSession", "Value={userSession}", ENDITEM, 
					"Name=username", "Value={userName}", ENDITEM, 
					"Name=password", "Value={password}", ENDITEM, 
					"Name=JSFormSubmit", "Value=off", ENDITEM, 
					"Name=login.x", "Value=59", ENDITEM, 
					"Name=login.y", "Value=10", ENDITEM, 
					LAST);
	
		lr_end_transaction("login",LR_AUTO);
	
		lr_think_time(5);
	
		lr_start_transaction("browsingItenerary");
		
			web_reg_find("Fail=NotFound",
					"Text=Itinerary",
					LAST);
		
			web_reg_save_param("flightId",
			"LB=name=\"flightID\" value=\"",
			"RB=\"",
			"Ord=ALL",
			"Search=Body",
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
		
		lr_start_transaction("CancelingFlight");
		
			flightIdLegth = lr_paramarr_len("flightId");	
			randomNumber = rand() % 3 + 1;
			
				
			if(randomNumber == 3 && flightIdLegth >= 3)
			{
				web_reg_find("Fail=Found",
				"Search=Body",
				"Text={flightId_1}",
				LAST);
					
				web_reg_find("Fail=Found",
				"Search=Body",
				"Text={flightId_2}",
				LAST);
					
				web_reg_find("Fail=Found",
				"Search=Body",
				"Text={flightId_3}",
				LAST);
					
				web_submit_form("itinerary.pl", 
				"Snapshot=t9.inf", 
				ITEMDATA, 
				"Name=1", "Value=on", ENDITEM,
				"Name=2", "Value=on", ENDITEM,
				"Name=3", "Value=on", ENDITEM,					
				"Name=removeFlights.x", "Value=61", ENDITEM, 
				"Name=removeFlights.y", "Value=10", ENDITEM, 
				LAST);
			}	
				
			else if(randomNumber == 2 && flightIdLegth >= 2)
			{
				web_reg_find("Fail=Found",
				"Search=Body",
				"Text={flightId_1}",
				LAST);
				
				web_reg_find("Fail=Found",
				"Search=Body",
				"Text={flightId_2}",
				LAST);
					
				web_submit_form("itinerary.pl", 
				"Snapshot=t9.inf", 
				ITEMDATA, 
				"Name=1", "Value=on", ENDITEM,
				"Name=2", "Value=on", ENDITEM,
				"Name=removeFlights.x", "Value=61", ENDITEM, 
				"Name=removeFlights.y", "Value=10", ENDITEM, 
				LAST);
			}	
			else
			{
				web_reg_find("Fail=Found",
				"Search=Body",
				"Text={flightId_1}",
				LAST);

				web_submit_form("itinerary.pl", 
				"Snapshot=t9.inf", 
				ITEMDATA, 
				"Name=1", "Value=on", ENDITEM, 
				"Name=removeFlights.x", "Value=61", ENDITEM, 
				"Name=removeFlights.y", "Value=10", ENDITEM, 
				LAST);
			}
			
		lr_end_transaction("CancelingFlight",LR_AUTO);
	
		lr_start_transaction("logout");
		
			web_reg_find("Fail=NotFound",
				"Text/IC=A Session ID has been created and loaded into a cookie",
				LAST);
	
			web_url("SignOff Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
				"Snapshot=t9.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("UC_04_ItineraryListBrowsing", LR_AUTO);

	return 0;
}