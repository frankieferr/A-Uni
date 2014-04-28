using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace Business
{
    [DataObject]
    public class Item
    {
        private static DataAccess.SouthwindTableAdapters.ItemsTableAdapter adapter = new DataAccess.SouthwindTableAdapters.ItemsTableAdapter();
        [DataObjectMethod(DataObjectMethodType.Update)]
        public static void UpdateItem(long original_ItemId, string name, decimal amount, bool income, datetime date)
        {
            adapter.Update(name, amount, income, date, original_ItemId);
        }

        [DataObjectMethod(DataObjectMethodType.Insert)]
        public static void InsertItem(long budgetId, string name, decimal amount, bool income, datetime data)
        {
            adapter.Insert(budgetId, name, amount, income, date);
        }

        [DataObjectMethod(DataObjectMethodType.Delete)]
        public static void DeleteItem(long original_ItemId)
        {
            adapter.Delete(original_ItemId);
        }

        [DataObjectMethod(DataObjectMethodType.Select)]
        public static Data.Southwind.ItemsDataTable GetItem(long budgetId)
        {
            return adapter.GetData(budgetId);

        }

    }
}
