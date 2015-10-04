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
using System.Collections.Generic;
using System.Windows.Forms;
using System.Threading;
using System.Configuration;


namespace Arcano
{
    public partial class FormSplash : Form
    {
        public FormSplash()
        {
            InitializeComponent();
            // Evitar que el label sobreponga backColor al PictureBox
            this.labelVerificar.Parent = pictureBoxSplash;
            // Cargo la version actual del empaquetado
            if (ConfigurationManager.AppSettings[""] != null)
            {
                this.labelVersion.Visible = false;
            }
            else
            {
                this.labelVersion.Text = ConfigurationManager.AppSettings["VersionActual"];
            }
        }
        
        // Evito que cierren el splash mientras verifica los campos de verificacion - App.config
        private void FormSplash_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
        }

        private void FormSplash_Shown(object sender, EventArgs e)
        {
            // Varifico la existencia de los campos requeridos por Arcano
            string mensaje = string.Empty;
            Dictionary<string, string>.KeyCollection ListaCampos = ArcanoConfig.GetLlavesRequeridasKeys();
            foreach (var campo in ListaCampos)
            {
                if (ConfigurationManager.AppSettings[campo] == null)
                {
                    Configuration config = ConfigurationManager.OpenExeConfiguration(Application.ExecutablePath);
                    config.AppSettings.Settings.Add(campo.ToString(), ArcanoConfig.GetLlavesRequeridas(campo).ToString());
                    config.Save(ConfigurationSaveMode.Minimal);
                }
                // Muestro el campo que esta revisando en el labelVerificar
                mensaje = "Arcano " + campo + " verificado...";
                this.labelVerificar.Text = mensaje;
                Application.DoEvents();
                Thread.Sleep(500);
            }
            this.labelVerificar.Text = "Cargando...";
            Application.DoEvents();
            Thread.Sleep(200);
            this.Dispose();
        }
    }
}
