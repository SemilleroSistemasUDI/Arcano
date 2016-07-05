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
using Syncfusion.Windows.Forms;
using System.Configuration;

namespace Arcano
{
    public partial class FormInicio : MetroForm
    {
        public FormInicio()
        {
            InitializeComponent();
            Thread.Sleep(500 * ArcanoConfig.GetCuentaDeLlavesRequeridas());
            this.TopMost = true;
        }

        private void FormInicio_Shown(object sender, EventArgs e)
        {
            this.TopMost = false;
            textBox1.Text = ConfigurationManager.AppSettings["ArcanoCore"];
        }

        private void FormInicio_Load(object sender, EventArgs e)
        {
            
            //bool cmd = Boolean.Parse(ConfigurationManager.AppSettings["CMD"]);
            //bool core = Boolean.Parse(ConfigurationManager.AppSettings["ArcanoCore"]);
            //bool archivo = Boolean.Parse(ConfigurationManager.AppSettings["RutaCSV"]);

            //if (!(cmd))
            //{
            //    panelNoCMD.Visible = true;
            //}

            //if (!(core))
            //{
            //    panelNoCore.Visible = true;
            //}

            //if (!(archivo))
            //{
            //    panelNoArchivo.Visible = true;
            //}

        }
    }
}
