#include"sd_fun.h"
Range create_text(int x, int y, int z){
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

int main(){
    init();
    response = echo_string(R"(
    - - text: one
    - text: two
    - text: three
    - text: four
    )");
    int mem_pos = 100, response_pos = 0, id = 1;
    while (in(response,response_pos, "text:")){
        ++id;
        Range r1 = create_text(id, response_pos, mem_pos);
        mem_pos += r1.len + 1;
        response_pos = r1.pos;
    }
    quit();
}