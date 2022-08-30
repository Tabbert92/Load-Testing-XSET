Action()
{
	lr_start_transaction("03_TicketBuying");
	
	web_reg_find("Fail=NotFound",
			"Text/IC=A Session ID has been created and loaded into a cookie",
			LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	
	lr_start_transaction("login");
	
		web_reg_find("Fail=NotFound",
				"Text/IC=User password was correct",
				LAST);

		web_submit_form("login.pl", 
			"Snapshot=t4.inf", 
			ITEMDATA, 
			"Name=username", "Value={userName}", ENDITEM, 
			"Name=password", "Value={password}", ENDITEM, 
			"Name=login.x", "Value=62", ENDITEM, 
			"Name=login.y", "Value=6", ENDITEM, 
			LAST);

	lr_end_transaction("login",LR_AUTO);
	

	lr_start_transaction("ticketSearch");

		web_image("Search Flights Button", 
			"Alt=Search Flights Button", 
			"Snapshot=t5.inf", 
			LAST);
	
		web_reg_find("Fail=NotFound",
				"Search=Body",
				"Text=Flight departing from",
				LAST);
	
		web_reg_save_param("outboundFlight",
					"LB=outboundFlight\" value=\"",
					"RB=\"",
					LAST);
	
		web_submit_form("reservations.pl", 
				"Snapshot=t6.inf", 
				ITEMDATA, 
				"Name=depart", "Value={flightDestenation}", ENDITEM, 
				"Name=departDate", "Value={departDate}", ENDITEM, 
				"Name=arrive", "Value={flightDestenation}", ENDITEM, 
				"Name=returnDate", "Value={returnDate}", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=roundtrip", "Value=<OFF>", ENDITEM, 
				"Name=seatPref", "Value={seatPref}", ENDITEM, 
				"Name=seatType", "Value={seatType}", ENDITEM, 
				"Name=findFlights.x", "Value=50", ENDITEM, 
				"Name=findFlights.y", "Value=7", ENDITEM, 
				LAST);
	
		web_reg_find("Fail=NotFound",
			"Text=Flight Reservation",
			LAST);

		web_submit_form("reservations.pl_2",
		"Snapshot=t7.inf",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=reserveFlights.x", "Value=61", ENDITEM,
		"Name=reserveFlights.y", "Value=10", ENDITEM,
		LAST);

	lr_end_transaction("ticketSearch",LR_AUTO);
	
	
	lr_start_transaction("ticketBuying");
	
		web_reg_find("Fail=NotFound",
			"Text=Thank you for booking through Web Tours.",
			LAST);

		web_submit_form("reservations.pl_3", 
			"Snapshot=t8.inf", 
			ITEMDATA, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={lastName}", ENDITEM, 
			"Name=address1", "Value={address1}", ENDITEM, 
			"Name=address2", "Value={address2}", ENDITEM, 
			"Name=pass1", "Value={firstName} {lastName}", ENDITEM, 
			"Name=creditCard", "Value=4200 0000 0000 0000", ENDITEM, 
			"Name=expDate", "Value=08/25", ENDITEM, 
			"Name=saveCC", "Value=<OFF>", ENDITEM, 
			"Name=buyFlights.x", "Value=34", ENDITEM, 
			"Name=buyFlights.y", "Value=9", ENDITEM, 
			LAST);

	lr_end_transaction("ticketBuying",LR_AUTO);


	lr_start_transaction("logout");
	
		web_reg_find("Fail=NotFound",
				"Text/IC=A Session ID has been created and loaded into a cookie",
				LAST);

		web_image("SignOff Button", 
			"Alt=SignOff Button", 
			"Snapshot=t9.inf", 
			LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("03_TicketBuying", LR_AUTO);

	return 0;
}