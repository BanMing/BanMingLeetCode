public class ArrayTest
{
    /// <summary>
    /// 二维数组中的查找
    /// </summary>
    public static bool FindNumIn2Array(int[][] array, int num)
    {
        #region 暴力
        // for (int i = 0; i < array.Length; i++)
        // {
        //     for (int j = 0; j < array[i].Length; j++)
        //     {
        //         if (num == array[i][j])
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;
        #endregion

        // int i = 0, j = 0;
        // while (0 < i && i < array.Length && 0 < j && j < array.Length)
        // {
        //     if (array[0][array[]])
        //     {

        //     }
        // }
        int j = array.Length - 1;
        for (int i = 0; i < array.Length; i++)
        {
            while (j >= 0)
            {
                if (array[i][j] > num)
                {
                    j--;
                    if (j < 0)
                    {
                        return false;
                    }
                }
                else if (array[i][j] < num)
                {
                    break;
                }
                else
                {
                    return true;
                }
            }

        }
        return false;
    }
}