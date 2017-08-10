main() {
  // Variables:
  // explicit
  const String s = 'hello, ' 'world!';
  print('Concatenation over line breaks is cool: $s\n'
      'As well as string interpolation: ${s.toUpperCase()}');

  // implicit:
  var testList = [2, 'hello'];
  assert(testList[0] == 2);
  assert(testList[1] == 'hello');
  print('testList: $testList');

  var gifts = {
    'first': 'partridge',
    'second': 'turtledoves',
  };

  assert(gifts['first'] == 'partridge');
  print('gifts: $gifts');

  assert(say('electron', 'I\'m +ve') == 'electron says I\'m +ve with iphone');
  print(say(
    'electron',
    'I\'m +ve',
  ));

  var lists = [4, 5, 6];
  doStuff(lists, gifts);
}

String say(String from, String msg, [String device = 'iphone']) {
  var result = '$from says $msg';

  if (device != null) {
    result = '$result with $device';
  }
  return result;
}

doStuff(
    [List<int> list = const [1, 2, 3],
    Map<String, String> gifts = const {'first': 'paper', 'second': 'cotton'}]) {
  print('lists: $list');
  print('gifts: $gifts');
}
