Action()
{

	lr_start_transaction("UC_02_TicketSearchWithoutBuying");
	
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
		
		lr_start_transaction("flightsBottonClick");

			web_url("Search Flights Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				LAST);
		
		lr_end_transaction("flightsBottonClick", LR_AUTO);

		lr_think_time(5);
			
		lr_start_transaction("startFindingFlights");
			
			lr_save_string(lr_eval_string("{flightDestination}"), "depart");
			
			lr_save_string(lr_eval_string("{flightDestination}"), "arrive");

				web_reg_find("Fail=NotFound",
			"Search=Body",
			"Text=Flight departing from <B>{depart}</B> to <B>{arrive}</B> on <B>{departDate}</B>",
			LAST);

	
			web_submit_data("reservations.pl", 
				"Action=http://localhost:1080/cgi-bin/reservations.pl", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
				"Snapshot=t4.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=advanceDiscount", "Value=0", ENDITEM, 
				"Name=depart", "Value={depart}", ENDITEM, 
				"Name=departDate", "Value={departDate}", ENDITEM, 
				"Name=arrive", "Value={arrive}", ENDITEM, 
				"Name=returnDate", "Value={returnDate}", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=seatPref", "Value={seatPref}", ENDITEM, 
				"Name=seatType", "Value={seatType}", ENDITEM, 
				"Name=.cgifields", "Value=roundtrip", ENDITEM, 
				"Name=.cgifields", "Value=seatType", ENDITEM, 
				"Name=.cgifields", "Value=seatPref", ENDITEM, 
				"Name=findFlights.x", "Value=54", ENDITEM, 
				"Name=findFlights.y", "Value=10", ENDITEM, 
				LAST);
	
		lr_end_transaction("startFindingFlights",LR_AUTO);

		lr_think_time(5);

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
	
	lr_end_transaction("UC_02_TicketSearchWithoutBuying", LR_AUTO);

	return 0;
}