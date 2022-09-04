Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(23);

	lr_start_transaction("NewUserRegistration");

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t2.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_submit_form("login.pl", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value=Vasily", ENDITEM, 
		"Name=password", "Value=1234567", ENDITEM, 
		"Name=passwordConfirm", "Value=1234567", ENDITEM, 
		"Name=firstName", "Value=Vasily", ENDITEM, 
		"Name=lastName", "Value=Pupkin", ENDITEM, 
		"Name=address1", "Value=smth", ENDITEM, 
		"Name=address2", "Value=123456", ENDITEM, 
		"Name=register.x", "Value=37", ENDITEM, 
		"Name=register.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("NewUserRegistration",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("ConfirmRegistration");

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("ConfirmRegistration",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}