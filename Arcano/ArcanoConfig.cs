using System.Collections.Generic;

namespace Arcano
{
    /// <summary>
    /// Contiene las estructuras de configuracion para Arcano
    /// </summary>
    static class ArcanoConfig
    {
        /// <summary>
        /// Diccionario estatico con los campos requeridos en el App.config por Arcano
        /// </summary>
        static Dictionary<string, string> _LlavesRequeridas = new Dictionary<string, string>
        {
            {"CMD", "false"},
            {"RutaCMD", @"C:\Windows\System32\cmd.exe"},
            {"ArcanoCore", "false"},
            {"CSV", @"\core\ArcanoCore.exe"},
            {"RutaCSV", "false"},
            {"CaracterCSV", @"\archivo.csv"}
        };

        /// <summary>
        /// Acceso a la lista de TKeys del direccionario
        /// </summary>
        public static Dictionary<string, string>.KeyCollection GetLlavesRequeridasKeys()
        {
            // Busco el campo en el diccionario estatico
            return _LlavesRequeridas.Keys;
        }

        /// <summary>
        /// Cantidad de registros en el diccionario
        /// </summary>
        public static int GetCuentaDeLlavesRequeridas()
        {
            // Busco el campo en el diccionario estatico
            return _LlavesRequeridas.Count;
        }

        /// <summary>
        /// Acceso al TValue del diccionario LlavesRequeridas conociendo el TKey
        /// </summary>
        public static string GetLlavesRequeridas(string campo)
        {
            // Busco el campo en el diccionario estatico
            string resultado;
            if (_LlavesRequeridas.TryGetValue(campo, out resultado))
            {
                return resultado;
            }
            else
            {
                return null;
            }
        }
    }
}
