#include "prelude"

yaml[0] = 0;
append(yaml, R"(
    View_2:
      style:
        backgroundColor: white
        width: 200
        height: 30
        marginLeft: 5
        marginTop: 5
        borderRadius: 10
      children: [Text_2m])");
append(yaml, R"(
    Text_2m:
      style:
        color: orange
        fontSize: 20
        marginLeft: 10
      pos: 100
      len: 5)");
append(yaml, R"(
    ScrollView_1:
      style:
        backgroundColor: green
        width: 210
        marginLeft: 5
        marginTop: 5
      children: [View_2])");
  append(yaml, R"(
    TextInput_last:
      style:
        position: absolute
        bottom: 0
        width: 640
        height: 30
        fontSize: 20
        borderColor: 'gray'
        borderWidth: 1
      pos: 1
      len: 80)");
write_at(mem, 100, "hello");
mem[1]=0;
#include "postlude"
