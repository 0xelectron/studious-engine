class Point {

  Point({this.title});

  final String title;
}

main() {
  var p = new Point(title: 'hello');
  print(p.title);
  print(p);
}
