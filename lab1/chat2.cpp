#include "prelude"

int n = 5;
yaml[0] = 0;
//creates the children
for (int i = 2; i < 2 + n; ++i)
{
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
    append(yaml, "    Text_", i, "m:\n");
    append(yaml, R"(
      style:
        color: orange
        fontSize: 20
        marginLeft: 10
      pos: 100
      len: 5
)");
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
write_at(mem, 100, "hello");
mem[1] = 0;
#include "postlude"
