#include"sd_fun.h"
Range create_text(int x){
    Range r2;
    r2 = find_value(response, x, "text:");
    append(yaml, response, r2);
    append(yaml, "\n");
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
    int response_pos = 0, id = 1;
    while (in(response,response_pos, "text:")){
        ++id;
        Range r1 = create_text(response_pos);
        response_pos = r1.pos;
    }
    quit();
}