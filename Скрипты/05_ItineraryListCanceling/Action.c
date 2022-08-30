Action()
{

	lr_start_transaction("05_IteneraryListCanseling");
	
	web_reg_find("Fail=NotFound",
			"Text/IC=A Session ID has been created and loaded into a cookie",
			LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("login");
	
		web_reg_find("Fail=NotFound",
						"Text/IC=User password was correct",
						LAST);

		web_submit_form("login.pl", 
			"Snapshot=t7.inf", 
			ITEMDATA, 
			"Name=username", "Value={userName}", ENDITEM, 
			"Name=password", "Value={password}", ENDITEM, 
			"Name=login.x", "Value=56", ENDITEM, 
			"Name=login.y", "Value=10", ENDITEM, 
			LAST);

	lr_end_transaction("login",LR_AUTO);


	lr_start_transaction("ItineraryBrowsing");
	
		web_reg_find("Fail=NotFound",
				"Text=Itinerary",
				LAST);

		web_image("Itinerary Button", 
			"Alt=Itinerary Button", 
			"Snapshot=t8.inf", 
			LAST);

	lr_end_transaction("ItineraryBrowsing",LR_AUTO);


	lr_start_transaction("DelitingBooking");

		web_submit_form("itinerary.pl", 
			"Snapshot=t9.inf", 
			ITEMDATA, 
			"Name=1", "Value=on", ENDITEM, 
			"Name=removeFlights.x", "Value=61", ENDITEM, 
			"Name=removeFlights.y", "Value=10", ENDITEM, 
			LAST);

	lr_end_transaction("DelitingBooking",LR_AUTO);


	lr_start_transaction("logout");
	
		web_reg_find("Fail=NotFound",
				"Text/IC=A Session ID has been created and loaded into a cookie",
				LAST);

		web_image("SignOff Button", 
			"Alt=SignOff Button", 
			"Snapshot=t10.inf", 
			LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("05_IteneraryListCanseling", LR_AUTO);

	return 0;
}