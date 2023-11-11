#pragma once
#include <cstdint>
#include <vulkan/vulkan.h>

namespace VkUtilities
{
	//In Vulkan, there are a lot of structs being created in order to use in other structs, pass them to function calls, and do other things like that.
	//Thier presence in VulkanRenderers (relatively) higher level function calls makes those calls much harder to read, so I'm creating a bunch of helper functions so 
	//I can move them here.

    // I think I might want to eventually create structs in VkConcepts to pass into these

    //Reminder: we are creating a bunch of copies this way and its slow AF. Strongly consider doing something slightly less screwey.

    VkDescriptorSetLayoutBinding CreateDescriptorBinding(uint32_t binding_, uint32_t descriptor_count_, VkDescriptorType descriptor_type_, VkShaderStageFlagBits stage_flags_)
    {
        VkDescriptorSetLayoutBinding result{};
        result.binding = binding_;
        result.descriptorCount = descriptor_count_;
        result.descriptorType = descriptor_type_;
        result.pImmutableSamplers = nullptr;
        result.stageFlags = stage_flags_;
        return result;
    }

    auto CreatePipeLineinfo(VkStructureType stype_, VkShaderStageFlagBits stage_, VkShaderModule module_, const char* pName_)
    {
        VkPipelineShaderStageCreateInfo result{};
        result.sType = stype_;
        result.stage = stage_;
        result.module = module_;
        result.pName = pName_;
        return result;
    }

    auto CreateSubmitInfo(VkStructureType stype_, uint32_t waitSemaphoreCount_, VkSemaphore waitsemaphores_[], VkPipelineStageFlags waitstages_[], uint32_t commandbuffercount_, const VkCommandBuffer* commandbuffer_, VkSemaphore signalsemaphores_[], uint32_t signalsemaphcount_)
    {
        VkSubmitInfo result{};



        result.sType = stype_;

        
        result.waitSemaphoreCount = waitSemaphoreCount_;
        result.pWaitSemaphores = waitsemaphores_;
        result.pWaitDstStageMask = waitstages_;

        result.commandBufferCount = commandbuffercount_;
        result.pCommandBuffers = commandbuffer_;

       
        result.signalSemaphoreCount = signalsemaphcount_;
        result.pSignalSemaphores = signalsemaphores_;

        return result;
    }
}
