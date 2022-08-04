hello = (x: string, y:string, z:string):string => {
  print(x);
  print(y);
  print(z);
  return x + y + z;
};

/*
* main method
*/
main = (argc: int, argv: Array<string>):int => {
  foo:string = "the first string\n";
  bar:string = "the second string\n";
  far:string = "the third string\n";

  hello(foo,bar,far);
  print("\n");
  print("Version: ");
  printVersion();
  print("\n");
  print("\n");
  print("\n");

  return 0;
};
