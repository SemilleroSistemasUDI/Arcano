#region Copyright Semillero Master Digital - GIDSAW. 2015-Presente.
// Copyright Semillero Master Digital - GIDSAW. 2015-Presente. 
// Todos los derechos reservados.
// Este codigo fuente esta licenciado bajo la licencia con el estilo BSD y la puede encontrar 
// en el archivo LICENSE en la raiz del proyecto. 
//
// =========================================================================================
//
// Copyright Semillero Master Digital - GIDSAW. 2015-Present. 
// All rights reserved.
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree. 
#endregion
using System;
using System.Threading;
using System.Windows.Forms;

namespace Arcano
{
    static class Program
    {
        public static FormSplash formSplash = null;

        /// <summary>
        /// Punto de entrada de la aplicacion.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            // Mostrar Splash
            Thread ThreadSplash = new Thread(new ThreadStart(
                    delegate
                    {
                        formSplash = new FormSplash();
                        Application.Run(formSplash);
                    }
            ));
            ThreadSplash.SetApartmentState(ApartmentState.STA);
            ThreadSplash.Start();

            // Despues de acabado el tiempo del splash
            FormInicio formInicio = new FormInicio();
            Application.Run(formInicio);
        }
    }
}
