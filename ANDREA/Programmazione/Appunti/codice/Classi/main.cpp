#include <iostream>
#include "Triangle_Rect.h"

// avendo A -> B, posso usare B al posto di A, ma non A al posto di B
// B è un A, ma A non è detto sia un B (A => B)
// ad esempio, questa funzione ritorna "Rectangle", ma nel codice ritorna chiaramente un Triangle_rect
Rectangle give_me_a_rectangle(Rectangle rect) {
    const int p = rect.perimeter();
    const auto tri_from_rect = Triangle_Rect(p/2, p/2);
    return tri_from_rect;
}

int main() {
    Triangle_Rect t_rect = Triangle_Rect(2, 3);
    std::cout << "Area del triangolo rettangolo: " << t_rect.area() << std::endl;
    std::cout << "Perimetro del triangolo rettangolo: " << t_rect.perimeter() << std::endl;
    return 0;
}
