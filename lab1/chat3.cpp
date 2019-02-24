#include "prelude"
response = echo_string(R"(
    - - text: one
      - text: two
      - text: three
      - text: four
)");
Range r_text ;
int response_pos = 0;
int mem_pos = 100;
int i = 2;
int n = 3;
yaml[0] = 0;
//creates the children
//for (int i = 2; i < 2 + n; ++i)
while (in(response,response_pos, "text:"))
{
    r_text = find_value(response, response_pos, "text:");
    response_pos =r_text.pos;
    append(yaml, "    View_", i, ":\n");
    append(yaml, R"(
      style:
        backgroundColor: white
        width: 200
        height: 30
        marginLeft: 5
        marginTop: 5
        borderRadius: 10
      )");
    append(yaml, "children: [Text_", i, "m]\n");
    write_at(mem, mem_pos, response, r_text);
    append(yaml, "    Text_", i, "m:\n");
    append(yaml, R"(
      style:
        color: orange
        fontSize: 20
        marginLeft: 10
      len: 5)");
    append(yaml, "\n      pos: ",mem_pos, "\n");
    mem_pos += r_text.len + 1;
    i++;
}
//append(yaml, "View_", i, ":");
append(yaml, R"(
    ScrollView_1:
      style:
        backgroundColor: green
        width: 210
        marginLeft: 5
        marginTop: 5
      )");
append(yaml, "children: [");
for (int i = 2; i < 2 + n; ++i)
{
    append(yaml, "View_", i, ", ");
}
append(yaml, "View_", 2 + n, "]\n");
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
      len: 80
      )");
//write_at(mem, 100, response, r_text);
mem[1] = 0;
#include "postlude"