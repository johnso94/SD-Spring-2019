#include"prelude"

//sends the code to somewhere
  query_str[0] = 0;
  Range t_range = find_value(yaml, "content:");
  if (t_range.len > 0) {
    append(query_str, "append_1:\n");
    append(query_str, "  johnso94:\n");
    append(query_str, "    messages:\n");
    append(query_str, "      text: ", yaml, t_range, "\n");
  }
  append(query_str, "read_1:\n");
  append(query_str, "  johnso94:\n");
  append(query_str, "    messages:\n");
  response = query_data_port(query_str);

//uses the response and writes something with it
Range r_text;
int response_pos = 0;
int mem_pos = 100;
int i = 2;
int n = 0;
yaml[0] = 0;
//creates the children
while (in(response,response_pos, "text:"))
{
    r_text = find_value(response, response_pos, "text:");
    n += 1;
    response_pos =r_text.pos;
    append(yaml, "    View_", i, ":\n");
    append(yaml, R"(
      style:
        backgroundColor: white
        width: 200
        height: auto
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
for (int i = 1; i < 2 + n; ++i)
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
#include"postlude"
