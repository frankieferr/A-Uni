using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace Business
{
    [DataObject]
    public class Budget
    {
        private static DataAccess.SouthwindTableAdapters.BudgetsTableAdapter adapter = new DataAccess.SouthwindTableAdapters.BudgetsTableAdapter();
        [DataObjectMethod(DataObjectMethodType.Update)]
        public static void UpdateBudget(long original_BudgetId, string name, string description)
        {
            adapter.Update(name, description, original_BudgetId);
        }

        [DataObjectMethod(DataObjectMethodType.Insert)]
        public static void InsertBudget(long userId, string name, string description)
        {
            adapter.Insert(userId, name, description);
        }

        [DataObjectMethod(DataObjectMethodType.Delete)]
        public static void DeleteBudget(long original_BudgetId)
        {
            adapter.Delete(original_BudgetId);
        }

        [DataObjectMethod(DataObjectMethodType.Select)]
        public static Data.Southwind.BudgetsDataTable GetBudget(long userId)
        {
            return adapter.GetData(userId);

        }

    }
}
