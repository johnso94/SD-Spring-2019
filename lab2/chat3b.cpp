#include"sd_fun.h"
Range create_text(int x, int y, int z){
    Range r2 = find_value(response, y, "text:");
    write_at(mem, z, response, r2);
    append(yaml, "Text_", x,":\n");
    append(yaml, R"(
      style:
        font: italic
        color: green
        fontSize: 30
        marginLeft: 10
        )");
    append(yaml, "pos: ", z, "\n");
    append(yaml, "len: ", r2.len, "\n");
    return r2;
}
void create_view(int x){
    int s = 2 * x;
    append(yaml, "View_", x,":\n");
    append(yaml, R"(
      style:
        width: 160
        height: 80
        backgroundColor: orange
        borderRadius: 0
        marginTop: 2
        MarginLeft: 10
        marginBottom: 2
        children: [)");
    append(yaml, "Text_", s,", ");
    s++;
    append(yaml, "Text_", s,"]\n");
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
        create_view(id);
        Range r1 = create_text(id, response_pos, mem_pos);
        mem_pos += r1.len + 1;
        response_pos = r1.pos;
    }
    append(yaml, R"(
    ScrollView_1:
      style:
        backgroundColor: black
        width: 210
        marginLeft: 5
        marginTop: 5
      )");
    append(yaml, "children: [");
    for (int i = 2; i < 2 + id; ++i)
    {
        append(yaml, "View_", i, ", ");
    }
    append(yaml, "]\n");
    quit();
}