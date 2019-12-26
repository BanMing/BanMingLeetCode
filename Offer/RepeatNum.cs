

// 数组中重复的数字
namespace Offer
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    public class RepeatNum
    {
        public static int Test(int[] array)
        {
            if (array == null || array.Length < 1)
            {
                return -1;
            }
            var temp = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                // 这里不满足题意
                if (array[i] < 0 || array[i] > array.Length)
                {
                    return -1;
                }
                if (temp[array[i]] == 0)
                {

                    temp[array[i]] = 1;
                }
                else if (temp[array[i]] == 1)
                {
                    return array[i];
                }
            }
            return -1;
        }

        public static bool Best(int[] numbers, ref int repeatNum)
        {
            if (numbers == null || numbers.Length < 1)
            {
                return false;
            }
            // 检测数组是否符合题意
            for (int i = 0; i < numbers.Length; i++)
            {
                if (numbers[i] < 0 || numbers[i] > numbers.Length)
                {
                    return false;
                }
            }
            // 使用数组索引与数组值对应比对
            for (int i = 0; i < numbers.Length; i++)
            {
                while (numbers[i] != i)
                {
                    if (numbers[i] == numbers[numbers[i]])
                    {
                        repeatNum = numbers[i];
                        return true;
                    }

                    int temp = numbers[i];
                    numbers[i] = numbers[temp];
                    numbers[temp] = temp;
                }
            }


            return false;
        }


        public static int Qestion2(int[] array)
        {
            // int startIndex = 0;
            int targetNum = array.Length / 2;
            int count = 0;

            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] <= targetNum)
                {
                    count++;
                }
            }
            if (count > targetNum)
            {
                targetNum /= 2;
            }
            else
            {
                targetNum = (targetNum + array.Length) / 2;
            }
            return 0;
        }
        private static int getNumCount(int[] array, int startIndex, int middleIndex, int endIndex)
        {
            int resCount = 0;
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] <= middleIndex)
                {
                    resCount++;
                }
            }

            return resCount;
        }
    }

}