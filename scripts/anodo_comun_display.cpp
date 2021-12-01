// ANODO COMUN => 5611BS

//MATRIZ PARA UN VISUALIZADOR DE 7 SEGMENTOS ANODO COMUN

// ANODO COMUN SE ALIMENTA CON => 5 VOLTIOS (5V)


// 0 => PARA ENCENDER EL LED RESPECTIVO DEL VISUALIZADOR
// 1 => PARA APAGAR EL LED RESPECTIVO DEL VISUALIZADOR

// number[fila][columna]
byte number[10][8] = {
    {0, 0, 0, 0, 0, 0, 1, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0, 1}, // 2
    {0, 0, 0, 0, 1, 1, 0, 1}, // 3
    {1, 0, 0, 1, 1, 0, 0, 1}, // 4 
    {0, 1, 0, 0, 1, 0, 0, 1}, // 5
    {0, 1, 0, 0, 0, 0, 0, 1}, // 6
    {0, 0, 0, 1, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0, 1}, // 8
    {0, 0, 0, 0, 1, 0, 0, 1} // 9
};
