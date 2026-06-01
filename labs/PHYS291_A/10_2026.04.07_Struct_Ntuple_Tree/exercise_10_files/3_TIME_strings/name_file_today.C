{
//   name_file_today.C     
//   root script to construct a date based filename
//   run             root name_file_today.C
//   or enter line by line
//
//   time_t    localtime()  asctime()  
//   strftime(outstring,80,"%format",localtime(&tt))
//
    time_t tt;
    char datepart_num[100];
    time(&tt); 
    cout << "\n                        ";
    cout << asctime( localtime( &tt ) );

    strftime(datepart_num,80,"%F",localtime(&tt));

    char filename[100];
    sprintf(filename,"data_%s.txt",datepart_num);
    
    cout << "the suggested filename is\n";
    cout << "\n                        ";
    cout << filename << "\n";
//
// other possibilities replacing "%F" are listed
// in here:
// http://www.cplusplus.com/reference/ctime/strftime/

}
