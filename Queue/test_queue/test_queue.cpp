#include "../Queue/Queue.h"

#include "gtest.h"

TEST(Queue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TQueue <int> q(3));
}

TEST(Queue, throws_when_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(Queue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(TQueue <int> q(MAX_SIZE + 1));
}

TEST(Queue, can_create_copied_queue)
{
	TQueue<int> q(10);

	ASSERT_NO_THROW(TQueue<int> q1(q));
}

TEST(Queue, copied_queue_is_equal_to_source_one)
{
	TQueue <int> q1(10), q2(10);
	for (int i = 0; i < q1.GetSize(); i++)
	{
		q1[i] = i + 1;
		q2[i] = q1[i];
	}
	EXPECT_EQ(q1, q2);
}

TEST(Queue, copied_queue_has_its_own_memory)
{
	TQueue <int> q1(10), q2(10);
	for (int i = 0; i < q1.GetSize(); i++)
	{
		q1[i] = i + 1;
		q2[i] = q1[i];
	}
	EXPECT_NE(&q1[0], &q2[0]);
}

TEST(Queue, can_assign_queue_to_itself)
{
	TQueue <int> q(10);
	for (int i = 0; i < q.GetSize(); i++)
	{
		q[i] = i + 1;
	}
	ASSERT_NO_THROW(q = q);
}

TEST(Queue, can_assign_queues_of_equal_size)
{
	TQueue <int> q1(10), q2(10);
	for (int i = 0; i <q1.GetSize(); i++)
	{
		q1[i] = i + 1;
	}
	ASSERT_NO_THROW(q2 = q1);
	EXPECT_EQ(q1.GetSize(), q2.GetSize());
	EXPECT_EQ(q1.GetDataCount(), q2.GetDataCount());
}

TEST(Queue, assign_operator_change_queue_size)
{
	TQueue <int> q1(10), q2(15);
	q2 = q1;
	EXPECT_EQ(q1.GetSize(), q2.GetSize());
}

TEST(Queue, can_assign_queues_of_different_size)
{
	TQueue <int> q1(10), q2(7);
	for (int i = 0; i < q1.GetSize(); i++)
	{
		q1[i] = i + 1;
	}
	ASSERT_NO_THROW(q2 = q1);
	EXPECT_EQ(q1.GetSize(), q2.GetSize());
	EXPECT_EQ(q1.GetDataCount(), q2.GetDataCount());
}

TEST(Queue, can_get_size)
{
	TQueue<int>q(10);
	EXPECT_EQ(10, q.GetSize());
}

TEST(Queue, can_get_data_count)
{
	TQueue<int> q(10);
	q.Push(1);
	q.Push(7);
	EXPECT_EQ(2, q.GetDataCount());
}

TEST(Queue, compare_queue_with_itself_return_true)
{
	TQueue <int>q(10);
	for (int i = 0; i < q.GetSize(); i++)
	{
		q[i] = i + 1;
	}
	EXPECT_EQ(1, q == q);
}

TEST(Queue, compare_equal_queues_return_true)
{
	TQueue <int> q1(10);
	for (int i = 0; i < q1.GetSize(); i++)
	{
		q1[i] = i + 1;
	}
	TQueue <int> q2 = q1;
	EXPECT_EQ(1, q1 == q2);
}

TEST(Queue, queues_with_different_size_are_not_equal)
{
	TQueue <int> q1(10), q2(15);
	EXPECT_EQ(1, q1 != q2);
}

TEST(Queue, can_put_element)
{
	TQueue<int> q(10);
	ASSERT_NO_THROW(q.Push(15));
	EXPECT_EQ(15, q.Back());
}

TEST(Queue, can_put_out_of_not_empty_queue)
{
	TQueue<int>q(10);
	q.Push(2);
	ASSERT_NO_THROW(q.Pop());
}

TEST(Queue, cant_put_out_of_empty_queue)
{
	TQueue<int>q(10);
	ASSERT_ANY_THROW(q.Pop());
}

TEST(Queue, empty_queue_return_true)
{
	TQueue <int> q(10);
	EXPECT_EQ(1, q.Empty());
}

TEST(Queue, can_check_that_queue_is_empty)
{
	TQueue <int> q(10);
	ASSERT_NO_THROW(q.Empty());
}

TEST(Queue, cant_put_in_full_queue)
{
	TQueue<int>q(1);
	q.Push(2);
	ASSERT_ANY_THROW(q.Push(2));
}

TEST(Queue, can_put_in_not_full_queue)
{
	TQueue<int>q(2);
	q.Push(1);
	ASSERT_NO_THROW(q.Push(2));
}

TEST(Queue, full_queue_return_true)
{
	TQueue<int>q(1);
	q.Push(2);
	EXPECT_EQ(1, q.Full());
}

TEST(Queue, can_check_that_queue_is_full)
{
	TQueue<int>q(10);
	ASSERT_NO_THROW(q.Full());
}

TEST(Queue, can_return_the_head)
{
	TQueue<int>q(10);
	q.Push(2);
	q.Push(5);
	ASSERT_NO_THROW(q.Front());
	EXPECT_EQ(2, q.Front());
}

TEST(Queue, cant_return_the_head_of_empty_queue)
{
	TQueue<int>q(10);
	q.Empty();
	ASSERT_ANY_THROW(q.Front());
}

TEST(Queue, can_return_the_tail)
{
	TQueue <int> q(3);
	q.Push(1);
	q.Push(5);
	q.Push(7);
	ASSERT_NO_THROW(q.Back());
	EXPECT_EQ(7, q.Back());
}

TEST(Queue, check_the_loopback)
{
	TQueue <int> q(3);
	q.Push(1);
	q.Push(5);
	q.Push(7);
	q.Pop();
	q.Push(9);
	EXPECT_EQ(9, q.Back());
	EXPECT_EQ(5, q.Front());
}






