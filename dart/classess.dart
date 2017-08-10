class Point {
  var x;
  var y;

  // Point(this.x, this.y);
  doSomething() {
    print("Point: doing something...");
  }

  toString() {
    return 'Point: ($x, $y)';
  }
}

class Line {
  Point p1;
  Point p2;

  // Line(this.p1, this.p2);
  doSomething() {
    print("Line: doing something...");
  }

  toString() {
    return 'Line: ($p1), ($p2)';
  }
}

main() {
  var l = (new Line()
    ..p1 = (new Point()
      ..x = 2
      ..y = 3
      ..doSomething())
    ..p2 = (new Point()
      ..x = 4
      ..y = 5
      ..doSomething())
    ..doSomething());

  print('Line l: $l');
}
