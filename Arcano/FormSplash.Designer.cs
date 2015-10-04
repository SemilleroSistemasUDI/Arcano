namespace Arcano
{
    partial class FormSplash
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormSplash));
            this.pictureBoxSplash = new System.Windows.Forms.PictureBox();
            this.labelVersion = new System.Windows.Forms.Label();
            this.labelVerificar = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxSplash)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBoxSplash
            // 
            this.pictureBoxSplash.BackColor = System.Drawing.Color.Transparent;
            this.pictureBoxSplash.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBoxSplash.Image = global::Arcano.Properties.Resources.SplashScreen;
            this.pictureBoxSplash.Location = new System.Drawing.Point(0, 0);
            this.pictureBoxSplash.Name = "pictureBoxSplash";
            this.pictureBoxSplash.Size = new System.Drawing.Size(249, 440);
            this.pictureBoxSplash.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxSplash.TabIndex = 0;
            this.pictureBoxSplash.TabStop = false;
            // 
            // labelVersion
            // 
            this.labelVersion.AutoSize = true;
            this.labelVersion.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelVersion.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(79)))), ((int)(((byte)(79)))), ((int)(((byte)(79)))));
            this.labelVersion.Location = new System.Drawing.Point(214, 409);
            this.labelVersion.Name = "labelVersion";
            this.labelVersion.Size = new System.Drawing.Size(31, 17);
            this.labelVersion.TabIndex = 1;
            this.labelVersion.Text = "v0.1";
            // 
            // labelVerificar
            // 
            this.labelVerificar.BackColor = System.Drawing.Color.Transparent;
            this.labelVerificar.Font = new System.Drawing.Font("Segoe UI", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelVerificar.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(79)))), ((int)(((byte)(79)))), ((int)(((byte)(79)))));
            this.labelVerificar.Location = new System.Drawing.Point(0, 278);
            this.labelVerificar.Name = "labelVerificar";
            this.labelVerificar.Size = new System.Drawing.Size(249, 17);
            this.labelVerificar.TabIndex = 2;
            this.labelVerificar.Text = "verificando Arcano...";
            this.labelVerificar.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // FormSplash
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(249, 440);
            this.Controls.Add(this.labelVerificar);
            this.Controls.Add(this.labelVersion);
            this.Controls.Add(this.pictureBoxSplash);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormSplash";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Arcano";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormSplash_FormClosing);
            this.Shown += new System.EventHandler(this.FormSplash_Shown);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxSplash)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBoxSplash;
        private System.Windows.Forms.Label labelVersion;
        private System.Windows.Forms.Label labelVerificar;
    }
}