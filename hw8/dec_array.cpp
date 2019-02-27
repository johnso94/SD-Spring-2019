#include"prelude"
mem[200]=0;
yaml[0] = 0;
float array[20] = {.05, .03, .06, .1, .24, .6, .89, .06, .57, .34, .98, .62, .47, .19, .54, .62, .85, .99, .999, .20};
int t;
for(int i=0; i < 20; i++){
    t = length_of(mem,200);
    write_at(mem, 200 + t, array [i]);
    t = length_of(mem,200);
    write_at(mem, 200 + t, "\n");
}

append(yaml, R"(
    Text_top:
      style:
        color: green
        fontSize: 30
        marginLeft: 10
      pos: 200
      len: 900)");

#include"postlude"
