Action()
{
	lr_start_transaction("UC_01_LoginLogout");

		loadStartingPage();
		
		lr_think_time(5);
		
		lr_start_transaction("login");
		
			login();
	
		lr_end_transaction("login",LR_AUTO);
	
		lr_think_time(5);
	
		lr_start_transaction("logout");
		
			logout();
	
		lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("UC_01_LoginLogout", LR_AUTO);

	return 0;
}