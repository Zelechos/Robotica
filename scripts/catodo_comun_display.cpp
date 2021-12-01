// CATODO COMUN => 5611AS

//MATRIZ PARA UN VISUALIZADOR DE 7 SEGMENTOS CATODO COMUN

// CATODO COMUN SE ALIMENTA CON => GND (GND)

// 0 => PARA ENCENDER EL LED RESPECTIVO DEL VISUALIZADOR
// 1 => PARA APAGAR EL LED RESPECTIVO DEL VISUALIZADOR

// number[fila][columna]
byte number[10][8] = {
    {1, 1, 1, 1, 1, 1, 0, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1, 0}, // 2
    {1, 1, 1, 1, 0, 0, 1, 0}, // 3
    {0, 1, 1, 0, 0, 1, 1, 0}, // 4 
    {1, 0, 1, 1, 0, 1, 1, 0}, // 5
    {1, 0, 1, 1, 1, 1, 1, 0}, // 6
    {1, 1, 1, 0, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0} // 9
};
