{
   // Tutorials first function (without extra graphics)
   // with "new" object pointer

   TF1 *f1 = new TF1("f1","sin(x)/x",0,10);
   f1->Draw();         //  instead of f1.Draw();
}
