#include"sd_fun.h"
Range create_text(int x, int y, int z){
    if (x % 2) { // id is odd
    Range r2 = find_value(response, y, "author:");
    write_at(mem, z, response, r2);
    append(yaml, "Text_", x,":\n");
    append(yaml, R"(
      style:
        color: green
        fontSize: 30
        marginLeft: 10
        fontFamily: italic
        )");
    append(yaml, "pos: ", z, "\n");
    append(yaml, "len: ", r2.len, "\n");
    return r2;
    }
    else {  // id is even
    Range r2 = find_value(response, y, "text:");
    write_at(mem, z, response, r2);
    append(yaml, "Text_", x,":\n");
    append(yaml, R"(
      style:
        color: green
        fontSize: 30
        marginLeft: 10
        )");
    append(yaml, "pos: ", z, "\n");
    append(yaml, "len: ", r2.len, "\n");
    return r2;
    }
}
void create_view(int x, bool indent){
    int s = 2 * x;
    append(yaml, "View_", x,":\n");
    append(yaml, R"(
      style:
        width: 160
        height: 80
        backgroundColor: orange
        borderRadius: 0
        marginTop: 2
        marginBottom: 2)");
    if (indent) { 
    append(yaml, "\nmarginLeft: 100 \n");
    }
    else{
    append(yaml, "\nmarginLeft: 10 \n");
    }
    append(yaml, "children:[Text_", s,", ");
    s++;
    append(yaml, "Text_", s,"]\n");
}
int main(){
    init();
    response = echo_string(R"(
    - - - text: one
        - author: Eric
    - - text: two
        - author: Kerrie
    - - text: three
        - author: Eric
    - - text: four
        - author: Kerrie
    )");
    int mem_pos = 100, response_pos = 0, id = 1;
    while (in(response,response_pos, "text:")){
        ++id;
        Range q = find_value(response, response_pos, "author:");
        write_at(mem, 900, response, q);
        bool is_Eric;
        if (mem[900] == 'E'&& mem[901] == 'r'&& mem[902] == 'i'&&mem[903] == 'c'){
          is_Eric = true;
        }
        else{
          is_Eric = false;
        }
        create_view(id, is_Eric);
        Range r1 = create_text(2 * id, response_pos, mem_pos);
        mem_pos += r1.len + 1;
        response_pos = r1.pos;
        Range r3 = create_text(2 * id + 1, response_pos, mem_pos);
        mem_pos += r3.len + 1;
        response_pos = r3.pos;
    }
    append(yaml, R"(
    ScrollView_1:
      style:
        backgroundColor: black
        width: 270
        marginLeft: 5
        marginTop: 5
      )");
    append(yaml, "children: [");
    for (int i = 2; i < id; ++i)
    {
        append(yaml, "View_", i, ", ");
    }
    append(yaml, "View_", id , "]\n");
    quit();
}