#include<cmath>
#include<iostream>
#include"prelude"

  if (length_of(yaml) < 50) {
    mem[100] = 0;
    mem[200] = 0;
  }
  Range t_range = find_value(yaml, "content:");
  long array[9] = {};
  int t;
  if (t_range.len > 0) {
    if (yaml[t_range.pos] == 'q'){
       write_at(mem,200, "goodbye");
    }
    else if(('2') > yaml[t_range.pos]){
    write_at(mem, 200, "invalid input");
    }
    else if(('9') < yaml[t_range.pos]){
    write_at(mem, 200, "invalid input");
    }
    else {
    int n = as_integer(yaml, t_range);
    write_at(mem, 200, "Power table for ");
        for(int i=1; i<=10; i++){
            array[i-1] = pow(n,i);
            t = length_of(mem,200);
            write_at(mem, 200 + t, array [i-1]);
            t = length_of(mem,200);
            write_at(mem, 200 + t, "\n");
        }
    }

}

  yaml[0] = 0;
  append(yaml, R"(
    Text_1:
      style:
        color: black
        fontSize: 30
        marginLeft: 10
      pos: 100
      len: 100)");
  write_at(mem, 100, "What number would you like me to compute the power table for? (enter 2-9 or q to quit)");
  append(yaml, R"(
    Text_top:
      style:
        color: black
        fontSize: 30
        marginLeft: 10
      pos: 200
      len: 900)");
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
  mem[1] = 0;  // initialize the text area to be empty

#include"postlude"