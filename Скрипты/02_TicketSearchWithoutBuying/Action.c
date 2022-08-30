Action()
{

	lr_start_transaction("02_TicketSearchWithoutBuying");
	
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
	

	lr_start_transaction("login");
	
		web_reg_find("Fail=NotFound",
				"Text/IC=User password was correct",
				LAST);

		web_submit_form("login.pl", 
			"Snapshot=t2.inf", 
			ITEMDATA, 
			"Name=username", "Value={userName}", ENDITEM, 
			"Name=password", "Value={password}", ENDITEM, 
			"Name=login.x", "Value=45", ENDITEM, 
			"Name=login.y", "Value=13", ENDITEM, 
			LAST);

	lr_end_transaction("login",LR_AUTO);

	
	lr_start_transaction("ticketSearch");

		web_image("Search Flights Button", 
			"Alt=Search Flights Button", 
			"Snapshot=t3.inf", 
			LAST);
	
		web_reg_find("Fail=NotFound",
			"Search=Body",
			"Text=Flight departing from",
			LAST);

		web_submit_form("reservations.pl", 
			"Snapshot=t4.inf", 
			ITEMDATA, 
			"Name=depart", "Value={flightDestination}", ENDITEM, 
			"Name=departDate", "Value={departDate}", ENDITEM, 
			"Name=arrive", "Value={flightDestination}", ENDITEM, 
			"Name=returnDate", "Value={returnDate}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=roundtrip", "Value=<OFF>", ENDITEM, 
			"Name=seatPref", "Value={seatPref}", ENDITEM, 
			"Name=seatType", "Value={seatType}", ENDITEM, 
			"Name=findFlights.x", "Value=64", ENDITEM, 
			"Name=findFlights.y", "Value=11", ENDITEM, 
			LAST);

	lr_end_transaction("ticketSearch",LR_AUTO);


	lr_start_transaction("logout");
	
		web_reg_find("Fail=NotFound",
				"Text/IC=A Session ID has been created and loaded into a cookie",
				LAST);

		web_image("SignOff Button", 
			"Alt=SignOff Button", 
			"Snapshot=t5.inf", 
			LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("02_TicketSearchWithoutBuying", LR_AUTO);

	return 0;
}