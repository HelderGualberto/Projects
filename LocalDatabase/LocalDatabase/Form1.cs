using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LocalDatabase
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void teste1BindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.teste1BindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.database1DataSet1);

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet1.teste1' table. You can move, or remove it, as needed.
            this.teste1TableAdapter.Fill(this.database1DataSet1.teste1);

        }
    }
}
