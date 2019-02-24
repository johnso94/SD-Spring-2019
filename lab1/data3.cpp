#include"prelude"

//sends the code to somewhere
yaml[0] = 0;
  append(yaml, R"(
    Text_top:
      style:
        color: black
        fontSize: 30
        marginLeft: 10
      pos: 100
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

  query_str[0] = 0;
  Range t_range = find_value(yaml, "content:");
  if (t_range.len > 0) {
    append(query_str, "append_1:\n");
    append(query_str, R"(
    johnso94:
    )");
    append(query_str, "    messages:\n");
    append(query_str, "      text: ", yaml, t_range, "\n");
  }
  append(query_str, "read_1:\n");
  append(query_str, R"()  
​
johnso94:
\n)");
  append(query_str, "    messages:\n");
  response = query_data_port(query_str);

#include"postlude"
